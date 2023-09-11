import { serve } from "bun";

let busy = false;

serve({
  development: process.env.NODE_ENV !== "production",
  port: "9887",
  fetch(req) {
    const url = new URL(req.url);
    if (url.pathname === "/on") {
      busy = true;
      return new Response();
    }
    if (url.pathname === "/off") {
      busy = false;
      return new Response();
    }

    if (url.pathname === "/state") {
      return new Response(JSON.stringify({ state: busy }), {
        headers: {
          "Content-Type": "application/json",
        },
      });
    }

    return new Response("404!");
  },
});
