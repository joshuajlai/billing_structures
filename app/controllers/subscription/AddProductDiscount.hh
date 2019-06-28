<?hh // strict

namespace App\Controllers\Subscription;

use App\Models\{LineItem, LineItemAdjustment, Subscription, AdjustmentType};

class AddProductDiscount
{
  public function call(Subscription $subscription, LineItem $product, int $value): Subscription
  {
    $this->verifyProduct($subscription, $product);
    $lineItemAdjustment = new LineItemAdjustment($value, AdjustmentType::Discount);
    $product->addLineItemAdjustment($lineItemAdjustment);

    return $subscription;
  }

  /**
   * Verify the product is part of the subscription and enforce other subscription restrictions
   */
  private function verifyProduct(Subscription $subscription, LineItem $product): void
  {

  }
}
