<?hh // strict

namespace App\Controllers\Plan;

use App\Models\{LineItem, LineItemAdjustment, Plan, AdjustmentType};

class AddProduct
{
  public function call(Plan $plan, string $name, int $value): Plan
  {
    $lineItem = new LineItem($name);
    $lineItemAdjustment = new LineItemAdjustment($value, AdjustmentType::Product);
    $lineItem->addLineItemAdjustment($lineItemAdjustment);
    $plan->addLineItem($lineItem);

    return $plan;
  }
}
