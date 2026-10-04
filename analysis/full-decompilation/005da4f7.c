
undefined1 FUN_005da4f7(int *param_1)

{
  char cVar1;
  undefined1 uVar2;
  int *piVar3;
  int iVar4;
  
  uVar2 = 0;
  cVar1 = FUN_005da398(param_1);
  if (cVar1 != '\0') {
    FUN_005da55e(param_1);
    piVar3 = (int *)(**(code **)(*param_1 + 0x18))();
    if (piVar3 == (int *)0x0) {
      (**(code **)(*param_1 + 0x10))();
      (**(code **)(*param_1 + 4))();
      do {
        iVar4 = (**(code **)(*param_1 + 8))();
      } while (iVar4 != 0);
      uVar2 = 1;
    }
    else {
      cVar1 = FUN_005da398(piVar3);
      if (cVar1 != '\0') {
        uVar2 = (**(code **)(*piVar3 + 0x2c))(param_1);
      }
    }
  }
  return uVar2;
}

