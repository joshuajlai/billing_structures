<?hh // strict

namespace App\Services;

class TaxDocument
{
  protected vec<TaxLineItem> $lineItems;

  public function __construct()
  {
    $this->lineItems = vec[];
  }

  public function addLineItem(TaxLineItem $lineItem): void
  {
    $this->lineItems[] = $lineItem;
  }

  public function getLineItems(): vec<TaxLineItem>
  {
    return $this->lineItems;
  }
}
