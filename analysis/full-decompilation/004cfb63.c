
undefined4 __thiscall FUN_004cfb63(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (param_2 == -1) {
    return 0;
  }
  iVar1 = FUN_004e9744(param_2);
  if (iVar1 == 0) {
    FUN_004e978e(param_2);
  }
  iVar1 = FUN_004e99a9();
  if (iVar1 == param_2) {
    iVar1 = FUN_004e9744(param_2);
    iVar3 = FUN_006359f2(DAT_006f6b5c,0,&cXObject::RTTI_Type_Descriptor,
                         &cXPerson::RTTI_Type_Descriptor,0);
    if (iVar1 != iVar3) {
      FUN_0051eaec();
    }
    if (iVar1 == 0) goto LAB_004cfbf6;
    FUN_00434d92(1);
  }
  else {
    FUN_004e99d7();
    uVar2 = FUN_004e99a9();
    *(undefined4 *)(param_1 + 0x1ec) = uVar2;
  }
  FUN_0057a14d(s_UI_click_006c7b54);
LAB_004cfbf6:
  *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) | 8;
  return 1;
}

