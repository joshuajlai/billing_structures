<?hh // strict

namespace App\Controllers\Invoice;

use App\Models\Invoice;

class Cancel
{
  public function call(Invoice $invoice): Invoice
  {
    $invoice->cancel();

    return $invoice;
  }
}
