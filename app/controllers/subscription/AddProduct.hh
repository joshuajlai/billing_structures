<?hh // strict

namespace App\Controllers\Subscription;

use App\Models\{LineItem, LineItemAdjustment, Subscription, AdjustmentType};

class AddProduct
{
  public function call(Subscription $subscription, string $name, int $value): Subscription
  {
    $lineItem = new LineItem($name);
    $lineItemAdjustment = new LineItemAdjustment($value, AdjustmentType::Product);
    $lineItem->addLineItemAdjustment($lineItemAdjustment);
    $subscription->addLineItem($lineItem);

    return $subscription;
  }
}
