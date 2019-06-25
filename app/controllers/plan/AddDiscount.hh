<?hh // strict

namespace App\Controllers\Plan;

use App\Models\{LineItem, LineItemAdjustment, Plan, AdjustmentType};

/**
 * Add a top level discount such as flat amount incentive. Does not support percentage.
 */
class AddDiscount
{
  public function call(Plan $plan, string $name, int $value): Plan
  {
    $lineItem = new LineItem($name);
    $lineItemAdjustment = new LineItemAdjustment($value, AdjustmentType::Discount);
    $lineItem->addLineItemAdjustment($lineItemAdjustment);
    $plan->addLineItem($lineItem);

    return $plan;
  }
}
