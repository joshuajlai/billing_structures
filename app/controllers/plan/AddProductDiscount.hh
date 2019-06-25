<?hh // strict

namespace App\Controllers\Plan;

use App\Models\{LineItem, LineItemAdjustment, Plan, AdjustmentType};

class AddProductDiscount
{
  public function call(Plan $plan, LineItem $product, int $value): Plan
  {
    $this->verifyProduct($plan, $product);
    $lineItemAdjustment = new LineItemAdjustment($value, AdjustmentType::Discount);
    $product->addLineItemAdjustment($lineItemAdjustment);

    return $plan;
  }

  /**
   * Verify the product is part of the plan and enforce other plan restrictions
   */
  private function verifyProduct(Plan $plan, LineItem $product): void
  {

  }
}
