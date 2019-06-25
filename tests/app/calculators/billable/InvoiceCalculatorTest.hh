<?hh // strict

namespace App\Calculators\Billable;

use Facebook\HackTest\HackTest;
use function Facebook\FBExpect\expect;

use type App\Calculators\Billable\InvoiceCalculator;
use type App\Models\Invoice;

class InvoiceCalculatorTest extends HackTest
{
  use \TestLoader;

  public function testTotal_Invoice(): void
  {
    $invoice = $this->generateInvoice();
    $calculator = new InvoiceCalculator($invoice);
    expect($calculator->total())->toBePHPEqual(330);
  }

  public function testSubtotal_Invoice(): void
  {
    $invoice = $this->generateInvoice();
    $calculator = new InvoiceCalculator($invoice);
    expect($calculator->subtotal())->toBePHPEqual(300);
  }

  public function testTax_Invoice(): void
  {
    $invoice = $this->generateInvoice();
    $calculator = new InvoiceCalculator($invoice);
    expect($calculator->tax())->toBePHPEqual(30);
  }
}
