
void __thiscall FUN_004a82db(int *param_1,int param_2,char param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = param_1[6];
  if ((iVar2 != param_2) || (param_3 != '\0')) {
    uVar1 = 0;
    FUN_00540a5b(0,iVar2);
    FUN_005406d1(uVar1,iVar2);
    FUN_0049eb08();
    *(undefined1 *)((int)param_1 + 0x4e) = 1;
    if (*(char *)((int)param_1 + 0x49) != '\0') {
      FUN_004ac287();
    }
    param_1[6] = param_2;
    FUN_00466fe4(param_2);
    if (*(char *)((int)param_1 + 0x49) != '\0') {
      FUN_004abb9e((char)param_1[0x7e]);
    }
    (**(code **)(*param_1 + 0x48))();
    (**(code **)(*DAT_006fe8bc + 0x18))();
    FUN_005db0b7();
  }
  return;
}

