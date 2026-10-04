
undefined4 __fastcall FUN_005f981c(int *param_1)

{
  char cVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  
  cVar1 = (**(code **)(*param_1 + 0x24))();
  if (*(char *)((int)param_1 + 0x25) == '\0') {
    piVar5 = param_1 + 0x20;
    for (iVar4 = 0; (*piVar5 != 0 && (iVar4 < 8)); iVar4 = iVar4 + 1) {
      (**(code **)(*(int *)*piVar5 + 0x48))((int *)*piVar5);
      piVar5 = piVar5 + 1;
    }
    cVar2 = (**(code **)(*(int *)param_1[0x19] + 0x1c))();
    if (cVar2 != '\0') {
      (**(code **)(*(int *)param_1[0x19] + 0x18))();
    }
    if ((cVar1 != '\0') && ((code *)param_1[0x1e] != (code *)0x0)) {
      (*(code *)param_1[0x1e])(param_1[0xc]);
    }
    uVar3 = 1;
  }
  else {
    uVar3 = (**(code **)(*param_1 + 0xe0))();
  }
  return uVar3;
}

