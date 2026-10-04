
void __fastcall FUN_00488018(int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  iVar2 = param_1[0xf];
  local_10 = *(undefined4 *)(iVar2 + 0xf4);
  local_c = *(undefined4 *)(iVar2 + 0xf8);
  local_8 = *(undefined4 *)(iVar2 + 0x110);
  iVar3 = *(int *)(iVar2 + 400);
  if (*(int *)(iVar2 + 400) != 0) goto LAB_00488059;
  while( true ) {
    iVar3 = iVar2;
    if (iVar2 == 0) {
      return;
    }
LAB_00488059:
    piVar1 = (int *)FUN_006359f2(iVar3,0,&cXMTObject::RTTI_Type_Descriptor,
                                 &cXCursorObject::RTTI_Type_Descriptor,0);
    if (piVar1 != (int *)param_1[0xf]) break;
    iVar2 = *(int *)(iVar3 + 0x18c);
  }
  if (piVar1 == (int *)0x0) {
    return;
  }
  param_1[0xf] = (int)piVar1;
  (**(code **)(*piVar1 + 0x50))(1);
  (**(code **)(*(int *)param_1[0xf] + 0x4c))(2);
  (**(code **)(*(int *)param_1[0xf] + 0x58))(&local_10,local_8,0,0,1);
  FUN_00486f2a();
  (**(code **)(*param_1 + 0x3c))();
  if (DAT_006e5780 == '\0') {
    return;
  }
  FUN_0040766a(0x91,0);
  DAT_006e5780 = 0;
  return;
}

