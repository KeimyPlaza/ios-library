/* Copyright 2017 Urban Airship and Contributors */

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Represents the possible error conditions when deserializing matcher from JSON.
 */
typedef NS_ENUM(NSInteger, UAJSONValueMatcherErrorCode) {
    /**
     * Indicates an error with the matcher JSON definition.
     */
   UAJSONValueMatcherErrorCodeInvalidJSON,
};

/**
 * The domain for NSErrors generated by `matcherWithJSON:error:`.
 */
extern NSString * const UAJSONValueMatcherErrorDomain;

/**
 * Defines a JSON value matcher.
 */
@interface UAJSONValueMatcher : NSObject

/**
 * The matcher's JSON payload.
 */
@property(nonatomic, readonly) NSDictionary *payload;

/**
 * Evaluates the object with the matcher.
 *
 * @param object The object to evaluate.
 * @return `YES` if the matcher matches the object, otherwise `NO`.
 */
- (BOOL)evaluateObject:(nullable id)object;

/**
 * Factory method to create a matcher for a number that is
 * at least the specified number.
 *
 * @param number The lower bound for the number.
 * @return A value matcher.
 */
+ (instancetype)matcherWhereNumberAtLeast:(NSNumber *)number;

/**
 * Factory method to create a matcher for a number between
 * the lowerNumber and higherNumber.
 *
 * @param lowerNumber The lower bound for the number.
 * @param higherNumber The upper bound for the number.
 * @return A value matcher.
 */
+ (instancetype)matcherWhereNumberAtLeast:(NSNumber *)lowerNumber atMost:(NSNumber *)higherNumber;

/**
 * Factory method to create a matcher for a number that is
 * at most the specified number.
 *
 * @param number The upper bound for the number.
 * @return A value matcher.
 */
+ (instancetype)matcherWhereNumberAtMost:(NSNumber *)number;

/**
 * Factory method to create a matcher for an exact number.
 *
 * @param number The expected number value.
 * @return A value matcher.
 */
+ (instancetype)matcherWhereNumberEquals:(NSNumber *)number;

/**
 * Factory method to create a matcher for an exact string.
 *
 * @param string The expected string value.
 * @return A value matcher.
 */
+ (instancetype)matcherWhereStringEquals:(NSString *)string;

/**
 * Factory method to create a matcher for the presence of a value.
 *
 * @param present `YES` if the value must be present, otherwise `NO`.
 * @return A value matcher.
 */
+ (instancetype)matcherWhereValueIsPresent:(BOOL)present;

/**
 * Factory method to create a matcher from a JSON payload.
 *
 * @param json The JSON payload.
 * @param error An NSError pointer for storing errors, if applicable.
 * @return A value matcher, or `nil` if the JSON is invalid.
 */
+ (nullable instancetype)matcherWithJSON:(id)json error:(NSError * _Nullable *)error;

@end

NS_ASSUME_NONNULL_END
