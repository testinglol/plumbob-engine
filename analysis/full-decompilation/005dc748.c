
int * __thiscall FUN_005dc748(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  int *local_8;
  
  local_8 = (int *)0x0;
  iVar3 = FUN_0060783f();
  if (iVar3 != 0) {
    if ((char)param_1[0xf] == '\0') {
      *(undefined1 *)(param_1 + 0xf) = 1;
    }
    piVar1 = (int *)param_1[0xe];
    piVar4 = (int *)*piVar1;
    if (piVar4 != piVar1) {
      do {
        cVar2 = (**(code **)(*(int *)piVar4[2] + 0x8c))(1);
        if ((cVar2 != '\0') &&
           (local_8 = (int *)FUN_005dc748(param_2,param_3), local_8 != (int *)0x0)) break;
        piVar4 = (int *)*piVar4;
      } while (piVar4 != (int *)param_1[0xe]);
    }
    *(undefined1 *)(param_1 + 0xf) = 0;
    if (local_8 != (int *)0x0) {
      return local_8;
    }
  }
  cVar2 = (**(code **)(*param_1 + 0x70))(param_2,param_3);
  if (cVar2 != '\0') {
    local_8 = param_1;
  }
  return local_8;
}

