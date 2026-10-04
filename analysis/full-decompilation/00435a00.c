
undefined4 FUN_00435a00(undefined4 *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int local_c;
  
  FUN_0043f371(*DAT_006e486c,param_2,0);
  while( true ) {
    if (local_c == 0) {
      return 0;
    }
    iVar1 = FUN_006359f2(local_c,0,&cXObject::RTTI_Type_Descriptor,&cXPortal::RTTI_Type_Descriptor,0
                        );
    if ((iVar1 != 0) && (iVar2 = FUN_00435968(), iVar2 == param_3)) break;
    FUN_0043f3b9();
  }
  *param_1 = *(undefined4 *)(*(int *)(iVar1 + 0x11c) + 8);
  uVar3 = FUN_00464232();
  return uVar3;
}

