
void __fastcall FUN_0046ed9c(undefined4 *param_1)

{
  uint uVar1;
  uint uVar2;
  int *piVar3;
  
  uVar1 = 0;
  for (piVar3 = (int *)*param_1; piVar3 != (int *)param_1[1]; piVar3 = piVar3 + 3) {
    uVar2 = piVar3[1] - *piVar3 >> 2;
    if (uVar1 < uVar2) {
      uVar1 = uVar2;
    }
  }
  return;
}

