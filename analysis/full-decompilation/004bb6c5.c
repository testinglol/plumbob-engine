
void __fastcall FUN_004bb6c5(int *param_1)

{
  int iVar1;
  
  if ((*param_1 != 0) && (iVar1 = 0, 0 < param_1[1] * 2 + 1)) {
    do {
      FUN_00634ecc(*(undefined4 *)(*param_1 + iVar1 * 4));
      iVar1 = iVar1 + 1;
    } while (iVar1 < param_1[1] * 2 + 1);
  }
  FUN_006321f0(*param_1);
  *param_1 = 0;
  return;
}

