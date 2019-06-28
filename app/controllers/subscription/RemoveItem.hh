<?hh // strict

namespace App\Controllers\Subscription;

use App\Models\{LineItem, LineItemAdjustment, Subscription, AdjustmentType};

class RemoveItem
{
  public function call(Subscription $subscription, LineItem $lineItem): Subscription
  {
    $subscription->removeLineItem($lineItem);

    return $subscription;
  }
}
