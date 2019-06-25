<?hh // strict

namespace App\Controllers\Invoice;

use App\Models\{Invoice, Ledger, LedgerType};
use App\Calculators\Billable\InvoiceCalculator;

class Finalize
{
  public function call(Invoice $invoice): Invoice
  {
    $this->generateLedger($invoice);
    $invoice->finalize();
    return $invoice;
  }

  private function generateLedger(Invoice $invoice): void
  {
    $calculator = new InvoiceCalculator($invoice);
    $ledger = new Ledger($calculator->total(), $invoice->getId(), LedgerType::Invoice);
    // save ledger to db
  }
}
