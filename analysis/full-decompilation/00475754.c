
void __fastcall FUN_00475754(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  
  *param_1 = &PTR_FUN_006678e8;
  if (param_1[4] != 0) {
    iVar2 = 0;
    if (0 < (int)param_1[1]) {
      do {
        iVar1 = *(int *)(param_1[4] + iVar2 * 4);
        if (iVar1 != 0) {
          FUN_00476018();
          FUN_006321f0(iVar1);
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < (int)param_1[1]);
    }
    FUN_006321f0(param_1[4]);
  }
  return;
}

