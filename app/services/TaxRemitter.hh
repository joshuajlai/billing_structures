<?hh // strict

namespace App\Services;

use HH\Lib\{C, Vec};

use App\Models\{AdjustmentType, Invoice, LineItem, LineItemAdjustment};

class TaxRemitter
{
  protected Invoice $invoice;

  public function __construct(Invoice $invoice)
  {
    $this->invoice = $invoice;
  }


  public function calculate(): Invoice
  {
    $taxDocument = $this->fakeServiceCall();
    $taxLineItems = $taxDocument->getLineItems();
    foreach ($this->invoice->getLineItems() as $lineItem) {
      $taxLineItem = C\find(
        $taxLineItems,
        $taxLineItem ==> $taxLineItem->getName() == $lineItem->getName()
      );
      if (null == $taxLineItem) {
        continue;
      }
      $this->processLineItem($lineItem, $taxLineItem);
    }

    return $this->invoice;
  }

  protected function processLineItem(
    LineItem $lineItem,
    TaxLineItem $taxLineItem
  ): void {
    $adjustments = $lineItem->getLineItemAdjustments();
    $taxAdjustment = C\find(
      $adjustments,
      $adjustment ==> $adjustment->getType() == AdjustmentType::Tax
    );
    if (null != $taxAdjustment) {
      $lineItem->removeLineItemAdjustment($taxAdjustment);
    }

    $taxAdjustment = new LineItemAdjustment(
      $taxLineItem->getValue(), AdjustmentType::Tax
    );
    $lineItem->addLineItemAdjustment($taxAdjustment);
  }

  protected function taxableAdjustments(vec<LineItemAdjustment> $adjustments): vec<LineItemAdjustment>
  {
    $validTypes = [AdjustmentType::Product, AdjustmentType::Discount];

    return Vec\filter(
      $adjustments,
      $adjustment ==> {
        return null !== C\find(
          $validTypes,
          $validType ==> $validType == $adjustment->getType()
        );
      }
    );
  }

  private function fakeServiceCall(): TaxDocument
  {
    $taxDocument = new TaxDocument();
    foreach ($this->invoice->getLineItems() as $lineItem) {
      $taxableAdjustments = $this->taxableAdjustments($lineItem->getLineItemAdjustments());
      $subtotal = 0;
      foreach ($taxableAdjustments as $adjustment) {
        $subtotal += $adjustment->getValue();
      }
      $value = (int) \round($subtotal * .1);
      $taxLineItem = new TaxLineItem($lineItem->getName(), $value);
      $taxDocument->addLineItem($taxLineItem);
    }

    return $taxDocument;
  }
}
