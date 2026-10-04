
ushort * __thiscall FUN_0040235e(undefined4 *param_1,undefined4 param_2,char param_3)

{
  short sVar1;
  int *piVar2;
  int iVar3;
  ushort *puVar4;
  ushort *puVar5;
  
  piVar2 = (int *)(**(code **)*param_1)(param_2);
  if ((piVar2 == (int *)0x0) ||
     (iVar3 = (**(code **)(*piVar2 + 0x38))(0x42434f4e,param_2,FUN_00402024), iVar3 == 0)) {
    return (ushort *)0x0;
  }
  sVar1 = FUN_004200a5(iVar3);
  if (sVar1 == 0) {
    FUN_00420048(iVar3);
  }
  puVar4 = (ushort *)FUN_00420048(iVar3);
  FUN_0042004f(iVar3);
  if (((((*puVar4 & 0x8000) != 0) && (param_3 != '\0')) &&
      (iVar3 = FUN_006359f2(piVar2,0,&iResFile::RTTI_Type_Descriptor,
                            &ObjResFile::RTTI_Type_Descriptor,0), iVar3 != 0)) &&
     (puVar5 = (ushort *)FUN_0045697c(param_2), puVar5 != (ushort *)0x0)) {
    return puVar5;
  }
  return puVar4;
}

