
void FUN_004e1d96(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  
  iVar1 = FUN_00425db3(param_1);
  if (iVar1 != 0) {
    iVar1 = FUN_004102e1();
    iVar3 = 0;
    if (0 < iVar1) {
      do {
        puVar2 = (undefined4 *)FUN_004102ab(iVar3);
        if (puVar2 != (undefined4 *)0x0) {
          param_1 = FUN_004e988f(*puVar2);
          if (param_1 != -1) {
            FUN_0042eab4(&param_1);
          }
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < iVar1);
    }
  }
  return;
}

