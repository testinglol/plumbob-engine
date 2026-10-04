
void __thiscall FUN_004a8392(int *param_1,char param_2)

{
  int iVar1;
  int *piVar2;
  
  if (param_2 != *(char *)((int)param_1 + 0x49)) {
    *(undefined1 *)(param_1 + 0x12) = 0;
    *(char *)((int)param_1 + 0x49) = param_2;
    *(undefined1 *)((int)param_1 + 0x4e) = 1;
    (**(code **)(*param_1 + 0x48))();
    FUN_0049eb08();
    piVar2 = param_1 + 0x82;
    for (iVar1 = 0x80; iVar1 != 0; iVar1 = iVar1 + -1) {
      *piVar2 = 0;
      piVar2 = piVar2 + 1;
    }
    FUN_004abb9e((char)param_1[0x7e]);
  }
  return;
}

