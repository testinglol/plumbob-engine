
undefined4 __thiscall FUN_004d3d3d(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  int *piVar2;
  undefined4 uVar3;
  char cVar4;
  undefined4 local_8;
  
  uVar3 = param_3;
  if ((DAT_006f2a08 != 0) && (piVar1 = *(int **)(DAT_006f2a08 + 0x88), piVar1 != (int *)0x0)) {
    piVar2 = (int *)piVar1[0x37];
    local_8 = param_1;
    if (piVar2 != (int *)0x0) {
      local_8 = param_2;
      FUN_004d26ba(piVar2,&local_8,&param_3);
      cVar4 = (**(code **)(*piVar2 + 0x74))(local_8,param_3);
      if (cVar4 != '\0') {
        return 1;
      }
    }
    cVar4 = (**(code **)(*piVar1 + 0x8c))(1);
    if (cVar4 != '\0') {
      param_3 = param_2;
      param_2 = uVar3;
      FUN_004d26ba(piVar1,&param_3,&param_2);
      cVar4 = (**(code **)(*piVar1 + 0x74))(param_3,param_2);
      if (cVar4 != '\0') {
        return 1;
      }
    }
  }
  return 0;
}

