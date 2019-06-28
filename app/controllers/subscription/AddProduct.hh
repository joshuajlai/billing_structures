<?hh // strict

namespace App\Controllers\Subscription;

use App\Models\{LineItem, LineItemAdjustment, Subscription, AdjustmentType, Product};

class AddProduct
{
  public function call(Subscription $subscription, string $sku): Subscription
  {
    $product = $this->findProduct($sku);
    $lineItem = clone($product);
    foreach ($product->getLineItemAdjustments() as $lineItemAdjustment) {
      $lineItem->addLineItemAdjustment($lineItemAdjustment);
    }
    $subscription->addLineItem($lineItem);

    return $subscription;
  }

  private function findProduct(string $sku): Product
  {
    return new Product($sku);
  }
}
