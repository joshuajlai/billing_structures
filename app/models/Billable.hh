<?hh // strict

namespace App\Models;

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
}
