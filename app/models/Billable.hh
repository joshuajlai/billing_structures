<?hh // strict

namespace App\Models;

use HH\Lib\Vec;

abstract class Billable
{
  private vec<LineItem> $lineItems = vec[];

  public function getLineItems(): vec<LineItem>
  {
    return $this->lineItems;
  }

  public function addLineItem(LineItem $lineItem): void
  {
    $this->lineItems[] = $lineItem;
  }

  public function removeLineItem(LineItem $lineItem): void
  {
    $this->lineItems = Vec\diff_by(
      $this->lineItems,
      vec[$lineItem],
      $existingLineItem ==> $existingLineItem->getId()
    );
  }
}
