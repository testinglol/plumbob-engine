
void __fastcall FUN_0058379c(int *param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    iVar2 = *piVar1;
    FUN_00599480(piVar1);
    *param_1 = 0;
    *(undefined4 *)(iVar2 + 0x98) = 1;
  }
  return;
}

