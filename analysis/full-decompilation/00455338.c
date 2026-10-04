
undefined4 __thiscall FUN_00455338(int param_1,int param_2,char *param_3)

{
  char *pcVar1;
  char cVar2;
  undefined2 uVar3;
  short sVar4;
  int iVar5;
  undefined2 *puVar6;
  byte bVar7;
  int iVar8;
  ushort uVar9;
  ushort uVar10;
  bool bVar11;
  undefined4 uVar12;
  TypeDescriptor *pTVar13;
  TypeDescriptor *pTVar14;
  undefined4 uVar15;
  
  pcVar1 = param_3;
  if (((byte)((ushort)*(undefined2 *)(param_3 + 2) >> 0xd) & 1) == 1) {
    uVar15 = 0;
    pTVar14 = &cXPerson::RTTI_Type_Descriptor;
    pTVar13 = &cXObject::RTTI_Type_Descriptor;
    uVar12 = 0;
    iVar5 = FUN_00407498((int)*(short *)(param_1 + 0x42));
  }
  else {
    uVar15 = 0;
    pTVar14 = &cXPerson::RTTI_Type_Descriptor;
    pTVar13 = &cXObject::RTTI_Type_Descriptor;
    uVar12 = 0;
    iVar5 = param_1;
  }
  iVar5 = FUN_006359f2(iVar5,uVar12,pTVar13,pTVar14,uVar15);
  if (iVar5 == 0) {
    param_3 = (char *)0x1c;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(&param_3,&DAT_00698f30);
  }
  puVar6 = (undefined2 *)FUN_00425769(*(undefined4 *)(*(int *)(iVar5 + 0x118) + 0x1c));
  FUN_0042a8e3(*puVar6);
  iVar5 = *(int *)(pcVar1 + 4);
  if (iVar5 == 0) {
    iVar5 = FUN_00407498((int)*(short *)(param_2 + 4));
    iVar5 = *(int *)(*(int *)(iVar5 + 0x118) + 0x1c);
  }
  cVar2 = *pcVar1;
  if (cVar2 == '\0') {
    uVar9 = *(ushort *)(pcVar1 + 2);
    if (((byte)uVar9 >> 1 & 1) == 1) {
      uVar10 = uVar9 & 0xc;
      if ((uVar9 & 0xc) == 0) {
        iVar8 = 0;
      }
      else if (uVar10 == 4) {
        iVar8 = 1;
      }
      else if (uVar10 == 8) {
        iVar8 = 2;
      }
      else {
        iVar8 = ((uVar10 == 0xc) - 1 & 0xfffffffc) + 3;
      }
      iVar8 = (int)*(short *)(param_1 + 0x3a + iVar8 * 2);
    }
    else {
      iVar8 = 1;
    }
    cVar2 = FUN_0041f38f(pcVar1[1],iVar5,iVar8);
LAB_00455789:
    bVar11 = cVar2 == '\0';
  }
  else {
    if (cVar2 == '\x01') {
      uVar9 = *(ushort *)(pcVar1 + 2);
      if (((byte)uVar9 >> 1 & 1) == 1) {
        uVar10 = uVar9 & 0xc;
        if ((uVar9 & 0xc) == 0) {
          iVar8 = 0;
        }
        else if (uVar10 == 4) {
          iVar8 = 1;
        }
        else if (uVar10 == 8) {
          iVar8 = 2;
        }
        else {
          iVar8 = ((uVar10 == 0xc) - 1 & 0xfffffffc) + 3;
        }
        iVar8 = (int)*(short *)(param_1 + 0x3a + iVar8 * 2);
      }
      else {
        iVar8 = 1;
      }
      cVar2 = FUN_0041f429(pcVar1[1],iVar5,iVar8);
      goto LAB_00455789;
    }
    if (cVar2 == '\x02') {
      uVar9 = *(ushort *)(pcVar1 + 2);
      if (((byte)uVar9 >> 1 & 1) == 1) {
        uVar10 = uVar9 & 0xc;
        if ((uVar9 & 0xc) == 0) {
          iVar5 = 0;
        }
        else if (uVar10 == 4) {
          iVar5 = 1;
        }
        else if (uVar10 == 8) {
          iVar5 = 2;
        }
        else {
          iVar5 = ((uVar10 == 0xc) - 1 & 0xfffffffc) + 3;
        }
        iVar5 = (int)*(short *)(param_1 + 0x3a + iVar5 * 2);
      }
      else {
        iVar5 = 1;
      }
      uVar10 = uVar9 & 0x300;
      if ((uVar9 & 0x300) == 0) {
        iVar8 = 0;
      }
      else if (uVar10 == 0x100) {
        iVar8 = 1;
      }
      else if (uVar10 == 0x200) {
        iVar8 = 2;
      }
      else {
        iVar8 = ((uVar10 == 0x300) - 1 & 0xfffffffc) + 3;
      }
      cVar2 = FUN_0041f56d(CONCAT22((short)((uint)iVar8 >> 0x10),
                                    *(undefined2 *)(param_1 + 0x3a + iVar8 * 2)),iVar5);
      goto LAB_00455789;
    }
    if (cVar2 == '\x03') {
      sVar4 = FUN_0041f662(pcVar1[1],iVar5,(int)&param_3 + 2);
      if (sVar4 == 0) {
        return 0;
      }
      bVar7 = pcVar1[2] & 0x60;
      if ((pcVar1[2] & 0x60U) == 0) {
        iVar5 = 0;
      }
      else if (bVar7 == 0x20) {
        iVar5 = 1;
      }
      else if (bVar7 == 0x40) {
        iVar5 = 2;
      }
      else {
        iVar5 = ((bVar7 == 0x60) - 1 & 0xfffffffc) + 3;
      }
      *(short *)(param_1 + 0x3a + iVar5 * 2) = sVar4;
      uVar9 = *(ushort *)(pcVar1 + 2) & 0x1800;
      if ((*(ushort *)(pcVar1 + 2) & 0x1800) == 0) {
        iVar5 = 0;
      }
      else if (uVar9 == 0x800) {
        iVar5 = 1;
      }
      else if (uVar9 == 0x1000) {
        iVar5 = 2;
      }
      else {
        iVar5 = ((uVar9 == 0x1800) - 1 & 0xfffffffc) + 3;
      }
      *(undefined2 *)(param_1 + 0x3a + iVar5 * 2) = param_3._2_2_;
      goto LAB_00455458;
    }
    if (cVar2 != '\x04') {
      if (cVar2 == '\x05') {
        FUN_0042573e((int)*(short *)(param_1 + 0x3a));
        uVar12 = FUN_00401f73();
        FUN_0041f4e7(1);
        uVar15 = 1;
      }
      else {
        if (cVar2 != '\x06') goto LAB_00455458;
        FUN_0042573e((int)*(short *)(param_1 + 0x3a));
        uVar12 = FUN_00401f73();
        FUN_0041f4e7(3);
        uVar15 = 3;
      }
      FUN_0041f38f(uVar15,uVar12,1);
      goto LAB_00455458;
    }
    uVar9 = *(ushort *)(pcVar1 + 2);
    uVar10 = uVar9 & 0x300;
    if ((uVar9 & 0x300) == 0) {
      iVar8 = 0;
    }
    else if (uVar10 == 0x100) {
      iVar8 = 1;
    }
    else if (uVar10 == 0x200) {
      iVar8 = 2;
    }
    else {
      iVar8 = ((uVar10 == 0x300) - 1 & 0xfffffffc) + 3;
    }
    param_3 = (char *)CONCAT22((short)((uint)iVar8 >> 0x10),
                               *(undefined2 *)(param_1 + 0x3a + iVar8 * 2));
    if ((pcVar1[2] & 1U) == 1) {
      uVar10 = uVar9 & 0x60;
      if ((uVar9 & 0x60) == 0) {
        iVar8 = 0;
      }
      else if (uVar10 == 0x20) {
        iVar8 = 1;
      }
      else if (uVar10 == 0x40) {
        iVar8 = 2;
      }
      else {
        iVar8 = ((uVar10 == 0x60) - 1 & 0xfffffffc) + 3;
      }
    }
    else {
      uVar10 = uVar9 & 0x60;
      if ((uVar9 & 0x60) == 0) {
        iVar8 = 0;
      }
      else if (uVar10 == 0x20) {
        iVar8 = 1;
      }
      else if (uVar10 == 0x40) {
        iVar8 = 2;
      }
      else {
        iVar8 = ((uVar10 == 0x60) - 1 & 0xfffffffc) + 3;
      }
      iVar5 = 0;
    }
    uVar3 = FUN_0041f69e(pcVar1[1],&param_3,iVar5);
    *(undefined2 *)(param_1 + 0x3a + iVar8 * 2) = uVar3;
    uVar9 = *(ushort *)(pcVar1 + 2) & 0x1800;
    if ((*(ushort *)(pcVar1 + 2) & 0x1800) == 0) {
      iVar5 = 0;
    }
    else if (uVar9 == 0x800) {
      iVar5 = 1;
    }
    else if (uVar9 == 0x1000) {
      iVar5 = 2;
    }
    else {
      iVar5 = ((uVar9 == 0x1800) - 1 & 0xfffffffc) + 3;
    }
    *(short *)(param_1 + 0x3a + iVar5 * 2) = (short)param_3;
    bVar11 = (short)param_3 == -1;
  }
  if (bVar11) {
    return 0;
  }
LAB_00455458:
  FUN_004cee86(0x4000000);
  return 1;
}

