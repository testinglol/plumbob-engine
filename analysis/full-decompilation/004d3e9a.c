
void __thiscall FUN_004d3e9a(int param_1,char param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (param_2 == '\0') {
    cVar1 = (**(code **)(**(int **)(param_1 + 0x11c0) + 0x8c))(1);
    if (cVar1 == '\0') {
      return;
    }
    FUN_004e609e();
    cVar1 = FUN_004e6133();
    iVar2 = **(int **)(param_1 + 0x11c0);
    if (cVar1 == '\0') {
      (**(code **)(iVar2 + 0x98))();
      return;
    }
    uVar3 = 0;
  }
  else {
    cVar1 = (**(code **)(**(int **)(param_1 + 0x11c0) + 0x8c))();
    if (cVar1 != '\0') {
      return;
    }
    FUN_004e609e();
    cVar1 = FUN_004e6133();
    iVar2 = **(int **)(param_1 + 0x11c0);
    if (cVar1 == '\0') {
      (**(code **)(iVar2 + 0x94))();
      return;
    }
    uVar3 = 1;
  }
  (**(code **)(iVar2 + 0xa8))(uVar3,0,0);
  return;
}

