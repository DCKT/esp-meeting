import Fastify from "fastify";
import cors from "@fastify/cors";

const fastify = Fastify({
  logger: false,
});

await fastify.register(cors, { origin: false });

let busy = false;

fastify.get("/on", async function handler(request, reply) {
  busy = true;
  return;
});
fastify.get("/off", async function handler(request, reply) {
  busy = false;
  return;
});
fastify.get("/state", async function handler(request, reply) {
  reply.send({ busy });
});

try {
  await fastify.listen({ port: 9887, host: "0.0.0.0" });
} catch (err) {
  fastify.log.error(err);
  process.exit(1);
}
