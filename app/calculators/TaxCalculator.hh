<?hh // strict

namespace App\Calculators;

use App\Models\Invoice;
use App\Services\TaxService;


class TaxCalculator
{
  protected Invoice $invoice;

  public function __construct(Invoice $invoice)
  {
    $this->invoice = $invoice;
  }

  public function totalTax(): int
  {
    $taxService = new TaxService();
    $invoice = $taxService->calculateTax($this->invoice);
    $total = 0;
    $lineItemCalculator = new ItemCalculator();
    foreach ($invoice->getLineItems() as $lineItem) {
      $total += $lineItemCalculator->tax($lineItem);
    }

    return $total;
  }
}
