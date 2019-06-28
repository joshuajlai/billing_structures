<?hh // strict

namespace App\Controllers\Subscription;

use App\Models\{LineItem, LineItemAdjustment, Subscription, AdjustmentType};

/**
 * Add a top level discount such as flat amount incentive. Does not support percentage.
 */
class AddDiscount
{
  public function call(Subscription $subscription, string $name, int $value): Subscription
  {
    $lineItem = new LineItem($name);
    $lineItemAdjustment = new LineItemAdjustment($value, AdjustmentType::Discount);
    $lineItem->addLineItemAdjustment($lineItemAdjustment);
    $subscription->addLineItem($lineItem);

    return $subscription;
  }
}
