<?php

/**
 * @generate-class-entries
 * @undocumentable
 */

/**
 * @throws \InvalidArgumentException If $privateKey is not a valid 32 byte secret
 */
function secp256k1_nostr_derive_pubkey(string $privateKey): string {}

/**
 * @throws \InvalidArgumentException If $privateKey is not a valid 32 byte secret
 * @throws \InvalidArgumentException If $hash is not 32 bytes long
 */
function secp256k1_nostr_sign(string $privateKey, string $hash): string {}

/**
 * @throws \InvalidArgumentException If $publicKey is not 32 bytes long
 * @throws \InvalidArgumentException If   $message is not 32 bytes long
 * @throws \InvalidArgumentException If $signature is not 64 bytes long
 */
function secp256k1_nostr_verify(string $publicKey, string $message, string $signature): bool {}
