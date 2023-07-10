<?php

/**
 * @generate-class-entries
 * @undocumentable
 */

/**
 * @throws \InvalidArgumentException If $privateKey is not a valid hex-encoded 32 byte private key (actual length: 64)
 * @throws \RuntimeException If unable to fetch entropy used to mitigate potential side channel attacks that could leak the private key
 */
function secp256k1_nostr_derive_pubkey(string $privateKey): string {}

/**
 * @throws \InvalidArgumentException If $privateKey is not a valid hex-encoded 32 byte private key (actual length: 64)
 * @throws \InvalidArgumentException If $hash is not a hex-encoded 32 byte string (actual length: 64)
 * @throws \RuntimeException If unable to fetch entropy used to mitigate potential side channel attacks that could leak the private key
 */
function secp256k1_nostr_sign(string $privateKey, string $hash): string {}

/**
 * @throws \InvalidArgumentException If $publicKey is not a valid hex-encoded 32 byte public key (actual length: 64)
 * @throws \InvalidArgumentException If   $message is not a hex-encoded 32 byte string (actual length: 64)
 * @throws \InvalidArgumentException If $signature is not a hex-encoded 64 byte string (actual length: 128)
 */
function secp256k1_nostr_verify(string $publicKey, string $hash, string $signature): bool {}
