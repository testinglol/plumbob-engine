
undefined4 __fastcall FUN_005f9798(int *param_1)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int *local_c;
  int *local_8;
  
  local_c = param_1;
  if (*(char *)((int)param_1 + 0x25) == '\0') {
    local_8 = (int *)0x0;
    iVar3 = param_1[0x20];
    piVar4 = param_1 + 0x20;
    for (; (iVar3 != 0 && ((int)local_8 < 8)); local_8 = (int *)((int)local_8 + 1)) {
      iVar3 = (**(code **)(*(int *)*piVar4 + 0x24))((int *)*piVar4,&local_c);
      if ((iVar3 == 0) && (((uint)local_c & 1) != 0)) {
        (**(code **)(*(int *)*piVar4 + 0x48))((int *)*piVar4);
        cVar1 = (**(code **)(*(int *)param_1[0x19] + 0x1c))();
        if (cVar1 != '\0') {
          (**(code **)(*(int *)param_1[0x19] + 0x18))();
        }
        if ((code *)param_1[0x1e] != (code *)0x0) {
          (*(code *)param_1[0x1e])(param_1[0xc]);
        }
      }
      piVar4 = piVar4 + 1;
      iVar3 = *piVar4;
    }
    uVar2 = 1;
  }
  else {
    local_8 = param_1;
    uVar2 = (**(code **)(*param_1 + 0xe0))();
  }
  return uVar2;
}

