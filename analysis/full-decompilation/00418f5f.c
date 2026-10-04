
void __fastcall FUN_00418f5f(int *param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)param_1[1]) {
    do {
      for (iVar2 = *piVar1; iVar2 != piVar1[1]; iVar2 = iVar2 + 0x5c) {
        if (*(int *)(iVar2 + 0xc) != 0) {
          FUN_00420028(*(int *)(iVar2 + 0xc));
        }
      }
      piVar1 = piVar1 + 5;
    } while (piVar1 != (int *)param_1[1]);
  }
  return;
}

