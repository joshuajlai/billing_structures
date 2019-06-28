<?hh //strict

namespace App\Models;

enum ExternalReferenceType: string {
  Stripe = 'stripe';
}
class ExternalReference
{
  private ExternalReferenceType $type;
  private string $referenceId;

  public function __construct(string $referenceId, ExternalReferenceType $type)
  {
    $this->referenceId = $referenceId;
    $this->type = $type;
  }
}
