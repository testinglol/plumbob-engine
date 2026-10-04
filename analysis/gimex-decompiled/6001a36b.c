
undefined4 * FUN_6001a36b(int *param_1,int param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  
  piVar1 = (int *)param_1[5];
  if (*param_1 == 0x464e5449) {
    puVar2 = FUN_6001a797((int)param_1,param_2);
  }
  else {
    puVar2 = (undefined4 *)FUN_600021ef(0x2890);
    if (puVar2 != (undefined4 *)0x0) {
      pbVar3 = (byte *)FUN_6001ad66((int)piVar1,param_2);
      puVar6 = puVar2;
      for (iVar5 = 0xa24; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar6 = 0;
        puVar6 = puVar6 + 1;
      }
      *puVar2 = 0x464e5446;
      puVar2[1] = 0x2890;
      puVar2[2] = 300;
      puVar2[3] = param_2;
      iVar5 = FUN_600011b3(pbVar3 + 2,1);
      puVar2[4] = iVar5;
      iVar5 = FUN_600011b3(pbVar3 + 3,1);
      puVar2[5] = iVar5;
      iVar5 = FUN_600011b3((byte *)(*piVar1 + 0xc),4);
      puVar2[0x10a] = iVar5;
      puVar2[0x10b] = 0;
      puVar2[0x10c] = 100;
      puVar2[6] = 8;
      puVar2[7] = piVar1[3];
      puVar2[0x10e] = 8;
      puVar2[0x10f] = 8;
      puVar2[0x110] = 8;
      puVar2[0x111] = 8;
      iVar5 = FUN_600011b3(pbVar3 + 9,1);
      puVar2[0x112] = -(int)(char)iVar5;
      iVar5 = FUN_600011b3(pbVar3 + 10,1);
      puVar2[0x113] = -(int)(char)iVar5;
      puVar2[0x114] = 0;
      puVar2[0x115] = 0;
      puVar2[0x116] = 3;
      iVar5 = FUN_600011b3(pbVar3 + 8,1);
      puVar2[0x21f] = (int)(char)iVar5 + puVar2[0x112];
      puVar2[0x220] = puVar2[0x113];
      puVar2[0x221] = puVar2[0x112];
      iVar5 = FUN_600011b3((byte *)(*piVar1 + 0x12),1);
      iVar4 = FUN_600011b3((byte *)(*piVar1 + 0x13),1);
      puVar2[0x222] = (int)(char)iVar5 + (int)(char)iVar4;
      iVar5 = FUN_600011b3((byte *)(*piVar1 + 0x12),1);
      puVar2[0x223] = (int)(char)iVar5;
      iVar5 = FUN_600011b3((byte *)(*piVar1 + 0x13),1);
      puVar2[0x224] = (int)(char)iVar5;
      FUN_600011b3(pbVar3,2);
      FUN_6009efea((undefined1 *)(puVar2 + 0x117),(byte *)"%04x \'%c\' %d");
      if (piVar1[3] == 1) {
        *(undefined1 *)((int)puVar2 + 0x2b) = 0xff;
        *(undefined1 *)((int)puVar2 + 0x2a) = 0;
        *(undefined1 *)((int)puVar2 + 0x29) = 0;
        *(undefined1 *)(puVar2 + 10) = 0;
        *(undefined1 *)((int)puVar2 + 0x2f) = 0xff;
        *(undefined1 *)((int)puVar2 + 0x2e) = 0xff;
        *(undefined1 *)((int)puVar2 + 0x2d) = 0xff;
        *(undefined1 *)(puVar2 + 0xb) = 0xff;
        puVar2[9] = 2;
        puVar2[8] = 0;
      }
      else if ((piVar1[3] == 4) && ((puVar2[0x10a] & 2) != 0)) {
        FUN_6001b189(puVar2 + 10,0xffffffff,0xff000000);
        puVar2[9] = 0x10;
        puVar2[8] = 0;
      }
      else if ((piVar1[3] == 4) && ((puVar2[0x10a] & 4) != 0)) {
        FUN_6001b2fc((int)(puVar2 + 10));
        puVar2[9] = 0x10;
        puVar2[8] = 0;
      }
      else {
        FUN_6001ad79((int)(puVar2 + 10));
        puVar2[9] = 0x10;
        puVar2[8] = 0;
      }
    }
  }
  return puVar2;
}

