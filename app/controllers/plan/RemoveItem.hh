<?hh // strict

namespace App\Controllers\Plan;

use App\Models\{LineItem, LineItemAdjustment, Plan, AdjustmentType};

class RemoveItem
{
  public function call(Plan $plan, LineItem $lineItem): Plan
  {
    $plan->removeLineItem($lineItem);

    return $plan;
  }
}
