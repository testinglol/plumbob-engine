
void __fastcall FUN_004c9dc0(int param_1)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)(param_1 + 0x1c);
  iVar1 = 3;
  do {
    FUN_006321f0(piVar2[-6]);
    FUN_006321f0(piVar2[-3] + *piVar2 * -4);
    FUN_006321f0(piVar2[4]);
    FUN_006321f0(piVar2[0xb] + -0x1fe);
    piVar2 = piVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  FUN_006321f0(*(undefined4 *)(param_1 + 0x38));
  return;
}

