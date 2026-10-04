
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __fastcall FUN_004674e7(int *param_1)

{
  short sVar1;
  float10 fVar2;
  
  sVar1 = *(short *)(*(int *)(*param_1 + 0x20) + 0x18);
  if (sVar1 != 1) {
    if (sVar1 == 2) {
      fVar2 = (float10)0;
      goto LAB_00467507;
    }
    if (sVar1 != 3) {
      fVar2 = (float10)1;
      goto LAB_00467507;
    }
  }
  fVar2 = (float10)_DAT_00666578;
LAB_00467507:
  return fVar2 * (float10)_DAT_006f010c;
}

