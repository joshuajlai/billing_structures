<?hh // strict

namespace App\Calculators\Billable;

use Facebook\HackTest\HackTest;
use function Facebook\FBExpect\expect;

use type App\Calculators\Billable\Estimation;
use type App\Models\Invoice;

class EstimationTest extends HackTest
{
  use \TestLoader;

  public function testTotal_Invoice(): void
  {
    $invoice = $this->generateInvoice();
    $calculator = new Estimation($invoice);
    expect($calculator->total())->toBePHPEqual(300);
  }

  public function testSubtotal_Invoice(): void
  {
    $invoice = $this->generateInvoice();
    $calculator = new Estimation($invoice);
    expect($calculator->subtotal())->toBePHPEqual(300);
  }

  public function testTax_Invoice(): void
  {
    $invoice = $this->generateInvoice();
    $calculator = new Estimation($invoice);
    expect($calculator->tax())->toBePHPEqual(0);
  }

  public function testTotal_Subscription(): void
  {
    $subscription = $this->generateSubscription();
    $calculator = new Estimation($subscription);
    expect($calculator->total())->toBePHPEqual(300);
  }

  public function testSubtotal_Subscription(): void
  {
    $subscription = $this->generateSubscription();
    $calculator = new Estimation($subscription);
    expect($calculator->subtotal())->toBePHPEqual(300);
  }

  public function testTax_Subscription(): void
  {
    $subscription = $this->generateSubscription();
    $calculator = new Estimation($subscription);
    expect($calculator->tax())->toBePHPEqual(0);
  }
}
