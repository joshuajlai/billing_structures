<?hh // strict

namespace App\Controllers\Invoice;

use App\Models\Invoice;

class Create
{
  public function call(): Invoice
  {
    return new Invoice();
  }
}
