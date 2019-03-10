
#include "MFRC522Debug.h"

/**
 * Returns a __FlashStringHelper pointer to the PICC type name.
 * 
 * @return const __FlashStringHelper *
 */
const __FlashStringHelper *MFRC522Debug::PICC_GetTypeName(MFRC522::PICC_Type piccType	///< One of the PICC_Type enums.
) {
	switch (piccType) {
		case MFRC522::PICC_TYPE_ISO_14443_4:		return F("PICC compliant with ISO/IEC 14443-4");
		case MFRC522::PICC_TYPE_ISO_18092:		return F("PICC compliant with ISO/IEC 18092 (NFC)");
		case MFRC522::PICC_TYPE_MIFARE_MINI:		return F("MIFARE Mini, 320 bytes");
		case MFRC522::PICC_TYPE_MIFARE_1K:		return F("MIFARE 1KB");
		case MFRC522::PICC_TYPE_MIFARE_4K:		return F("MIFARE 4KB");
		case MFRC522::PICC_TYPE_MIFARE_UL:		return F("MIFARE Ultralight or Ultralight C");
		case MFRC522::PICC_TYPE_MIFARE_PLUS:		return F("MIFARE Plus");
		case MFRC522::PICC_TYPE_MIFARE_DESFIRE:	return F("MIFARE DESFire");
		case MFRC522::PICC_TYPE_TNP3XXX:			return F("MIFARE TNP3XXX");
		case MFRC522::PICC_TYPE_NOT_COMPLETE:	return F("SAK indicates UID is not complete.");
		case MFRC522::PICC_TYPE_UNKNOWN:
		default:						return F("Unknown type");
	}
} // End PICC_GetTypeName()

/**
 * Returns a __FlashStringHelper pointer to a status code name.
 * 
 * @return const __FlashStringHelper *
 */
const char *MFRC522Debug::GetStatusCodeName(MFRC522::StatusCode code	///< One of the StatusCode enums.
) {
	switch (code) {
		case MFRC522::MFRC522_STATUS_OK:				return "Success.";
		case MFRC522::MFRC522_STATUS_ERROR:			return "Error in communication.";
		case MFRC522::MFRC522_STATUS_COLLISION:		return "Collission detected.";
		case MFRC522::MFRC522_STATUS_TIMEOUT:		return "Timeout in communication.";
		case MFRC522::MFRC522_STATUS_NO_ROOM:		return "A buffer is not big enough.";
		case MFRC522::MFRC522_STATUS_INTERNAL_ERROR:	return "Internal error in the code. Should not happen.";
		case MFRC522::MFRC522_STATUS_INVALID:		return "Invalid argument.";
		case MFRC522::MFRC522_STATUS_CRC_WRONG:		return "The CRC_A does not match.";
		case MFRC522::MFRC522_STATUS_MIFARE_NACK:	return "A MIFARE PICC responded with NAK.";
		default:					return "Unknown error";
	}
} // End GetStatusCodeName()
