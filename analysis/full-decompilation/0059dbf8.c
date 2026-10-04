
void FUN_0059dbf8(int param_1,int param_2,undefined4 param_3,char param_4)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  
  bVar2 = *(short *)(param_2 + 0x600) < 0x12;
  bVar1 = bVar2;
  if ((((param_4 != '\0') && (*(int *)(param_2 + 0xa50) == param_1)) &&
      (iVar3 = *(int *)(param_2 + 0xa54), iVar3 != 0)) &&
     ((*(short *)(*(int *)(iVar3 + 0x118) + 0x12) == 2 &&
      (iVar3 = FUN_006359f2(iVar3,0,&cXObject::RTTI_Type_Descriptor,&cXPerson::RTTI_Type_Descriptor,
                            0), iVar3 != 0)))) {
    bVar1 = *(short *)(iVar3 + 0x600) < 0x12;
  }
  if (bVar2) {
    if (bVar1) {
      iVar3 = FUN_00457d14();
    }
    else {
      iVar3 = FUN_00457d5c();
    }
  }
  else if (bVar1) {
    iVar3 = FUN_00457d38();
  }
  else {
    iVar3 = FUN_00457ccc();
  }
  pcVar5 = (char *)0x0;
  if (iVar3 != 0) {
    pcVar4 = (char *)FUN_004705f2((short)param_3 + 1,0xffffffff);
    if (((pcVar4 == (char *)0x0) || (*pcVar4 != '\0')) &&
       ((pcVar5 = pcVar4, pcVar4 != (char *)0x0 && (*pcVar4 != '\0')))) goto LAB_0059dcd3;
  }
  FUN_004f6f07(param_1,param_2,iVar3,param_3);
LAB_0059dcd3:
  FUN_0059dabd(param_2,pcVar5);
  return;
}

