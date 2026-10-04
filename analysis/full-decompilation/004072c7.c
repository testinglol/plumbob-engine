
void FUN_004072c7(void)

{
  int iVar1;
  char cVar2;
  short sVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  iVar1 = *(int *)(*DAT_006e486c + 0x14);
  local_8 = iVar1;
  local_c = FUN_0043ac74(s_comeandsee_006c0f14);
  if ((((local_c != 0) && (cVar2 = FUN_004074f7(), cVar2 == '\0')) &&
      (cVar2 = FUN_0040750e(), cVar2 == '\0')) &&
     ((cVar2 = FUN_00407525(), cVar2 == '\0' && (cVar2 = FUN_004074d9(), cVar2 == '\0')))) {
    for (iVar1 = *(int *)(iVar1 + 0x30); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0xe0)) {
      if (((*(short *)(*(int *)(iVar1 + 0x118) + 0x12) == 4) &&
          (cVar2 = FUN_00432644(), cVar2 != '\0')) &&
         ((*(short *)(iVar1 + 0x8e) == 0 && ((*(byte *)(iVar1 + 0x5b) & 0x40) == 0)))) {
        iVar4 = FUN_006359f2(iVar1,0,&cXObject::RTTI_Type_Descriptor,
                             &cXMTObject::RTTI_Type_Descriptor,0);
        if (iVar4 != 0) {
          iVar6 = *(int *)(iVar4 + 400);
          if (*(int *)(iVar4 + 400) == 0) {
            iVar6 = iVar4;
          }
          if (iVar6 != iVar4) goto LAB_00407485;
        }
        piVar5 = (int *)FUN_0040753c(iVar1);
        if (piVar5 == (int *)0x0) {
          iVar4 = FUN_004352b2();
          if ((iVar4 == 0) && (cVar2 = FUN_004074bc(), cVar2 == '\x01')) {
            sVar3 = FUN_00440b6d(local_c);
            iVar4 = (int)sVar3;
            piVar5 = (int *)FUN_00407498(iVar4);
            if (piVar5 != (int *)0x0) {
              FUN_004650d0(iVar4,1);
              FUN_004651b1(iVar4,0,1);
              goto LAB_0040742d;
            }
          }
        }
        else {
LAB_0040742d:
          FUN_00407200(&local_14,iVar1);
          iVar4 = piVar5[0x3d];
          iVar6 = piVar5[0x3e];
          cVar2 = FUN_00432644();
          if ((((cVar2 == '\0') || (iVar6 != local_10)) || (iVar4 != local_14)) ||
             (*(int *)(iVar1 + 0x110) != piVar5[0x44])) {
            (**(code **)(*piVar5 + 0x58))(&local_14,*(undefined4 *)(iVar1 + 0x110),0,0,1);
          }
        }
      }
LAB_00407485:
    }
  }
  return;
}

