
void __fastcall FUN_00423621(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined1 local_2c [4];
  int local_28;
  int local_18;
  int local_14;
  int local_10;
  undefined4 local_c;
  int local_8;
  
  local_8 = 0;
  local_c = *(undefined4 *)(param_1 + 0x110);
  iVar1 = *(int *)(param_1 + 0xf4);
  iVar2 = *(int *)(param_1 + 0xf8);
  local_10 = *(int *)(param_1 + 0x11c);
  do {
    local_18 = iVar1;
    local_14 = iVar2;
    piVar3 = (int *)FUN_004222bd(local_8);
    local_14 = local_14 + piVar3[1];
    local_18 = local_18 + *piVar3;
    FUN_004235c6(local_2c,&local_18,local_c);
    while (local_28 != 0) {
      if (*(int *)(local_28 + 0x11c) == local_10) {
        FUN_006359f2(local_28,0,&cXObject::RTTI_Type_Descriptor,&cXMTObject::RTTI_Type_Descriptor,0)
        ;
        FUN_0042339b(param_1);
      }
      FUN_0043f3b9();
    }
    local_8 = local_8 + 2;
  } while (local_8 < 8);
  FUN_004234de();
  return;
}

