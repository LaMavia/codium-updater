//
[%raw "require('isomorphic-fetch')"];
open BsCheerio;
open Js.Promise;
open PromiseMonad;

let releses_url = "https://github.com/VSCodium/vscodium/releases";
Fetch.fetch(releses_url)
>>= Fetch.Response.text
>>- (
  html => {
    Cheerio.load(html)
    ->Cheerio.select(
        {js|.d-flex.flex-items-center.min-width-0[href$="amd64.deb"]|js},
      )
    ->Element.attr1("href");
  }
)
>>- (
  href =>
    href
    ->Js.Nullable.toOption
    ->Belt.Option.getExn
    |>(Js.String2.concat("https://github.com"))
)
>>- Js.Console.log;