
void __thiscall
FUN_00485b61(int param_1,undefined4 param_2,undefined4 param_3,uint param_4,int param_5)

{
  char cVar1;
  SHORT SVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  int local_34;
  short local_30;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined1 local_18 [4];
  int local_14;
  short local_10;
  short sStack_e;
  int local_c;
  char local_5;
  
  GetKeyState(0x10);
  SVar2 = GetKeyState(0x11);
  local_5 = SVar2 < 0;
  uVar3 = FUN_00492b26();
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  if ((local_5 == '\0') || ((*(int *)(param_1 + 0x34) != 4 && (*(int *)(param_1 + 0x34) != 3)))) {
    cVar1 = '\0';
  }
  else {
    cVar1 = '\x01';
  }
  *(char *)(param_1 + 0x79) = cVar1;
  *(undefined1 *)(param_1 + 0xac) = 0;
  *(undefined1 *)(param_1 + 0x7a) = 0;
  if ((*(char *)(param_1 + 0x77) == '\0') || (cVar1 == '\0')) {
    if (*(int *)(param_1 + 0x3c) != 0) {
      FUN_0043270d(*(undefined4 *)(*(int *)(param_1 + 0x3c) + 0x1ac));
      if (local_34 == 0) {
        local_c = 0;
      }
      else {
        FUN_0043270d(*(undefined4 *)(*(int *)(param_1 + 0x3c) + 0x1ac));
        local_c = (int)local_30;
      }
      FUN_00486472();
      local_20 = *(undefined4 *)(*(int *)(param_1 + 0x3c) + 0xf4);
      local_1c = *(undefined4 *)(*(int *)(param_1 + 0x3c) + 0xf8);
      cVar1 = FUN_00432644();
      if (cVar1 != '\0') {
        (**(code **)(**(int **)(param_1 + 0x3c) + 0x50))(1);
      }
      if (*(char *)(param_1 + 0x97) == '\0') {
        return;
      }
      if (*(int *)(param_1 + 0x34) == 5) {
        param_4 = *(int *)(param_1 + 0x58) + 1;
      }
      else {
        param_4 = FUN_00492b26();
      }
      iVar5 = param_5;
      *(int *)(param_1 + 0x6c) = (int)*(short *)(param_5 + 0xe);
      *(int *)(param_1 + 0x70) = (int)*(short *)(param_5 + 0xc);
      if (*(int **)(param_1 + 0x30) != (int *)0x0) {
        (**(code **)(**(int **)(param_1 + 0x30) + 0xc))();
      }
      (**(code **)(**(int **)(param_1 + 0x3c) + 0x58))(&local_20,param_4,0,local_c,1);
      if (*(char *)(param_1 + 0x7b) != '\0') {
        iVar7 = *(int *)(param_1 + 0x70) - *(int *)(param_1 + 0x60);
        local_14 = *(int *)(*(int *)(param_1 + 0x3c) + 0x1ac);
        iVar5 = *(int *)(param_1 + 0x6c) - *(int *)(param_1 + 0x5c);
        if (0x24 < iVar7 * iVar7 + iVar5 * iVar5) {
          *(undefined1 *)(param_1 + 0x80) = 0;
          if (iVar5 < 0) {
            if (iVar7 < 0) {
              *(undefined4 *)(param_1 + 0x7c) = 6;
            }
            else {
              *(undefined4 *)(param_1 + 0x7c) = 4;
            }
          }
          else if (iVar7 < 0) {
            *(undefined4 *)(param_1 + 0x7c) = 0;
          }
          else {
            *(undefined4 *)(param_1 + 0x7c) = 2;
          }
          uVar4 = *(int *)(param_1 + 0x7c) + *(int *)(DAT_006e54d8 + 0x84) * -2 & 7;
          if ((int)*(short *)(local_14 + 0x4c) != uVar4) {
            iVar5 = FUN_00435032();
            FUN_004226ef(uVar4 - iVar5 & 7);
            *(undefined4 *)(param_1 + 0xa8) = 0xfffffff0;
            *(undefined4 *)(param_1 + 0xa4) = 0xfffffff0;
            *(undefined1 *)(param_1 + 0x96) = 1;
            FUN_00492cfb();
          }
          if ((((*(int *)(*(int *)(param_1 + 0x3c) + 0x1ac) == 0) ||
               (*(short *)(*(int *)(param_1 + 0x3c) + 0x1b0) == 0)) &&
              (*(int *)(param_1 + 0x34) == 5)) && (cVar1 = FUN_00487563(), cVar1 != '\0')) {
            cVar1 = (**(code **)(**(int **)(param_1 + 0x3c) + 0x54))(&local_20,param_4,0,0);
            if (cVar1 != '\0') {
              (**(code **)(**(int **)(param_1 + 0x3c) + 0x58))(&local_20,param_4,0,0,1);
            }
            if (((*(int *)(*(int *)(param_1 + 0x3c) + 0x1ac) == 0) ||
                (*(short *)(*(int *)(param_1 + 0x3c) + 0x1b0) == 0)) &&
               (*(int **)(param_1 + 0x30) != (int *)0x0)) {
              (**(code **)(**(int **)(param_1 + 0x30) + 0xc))();
            }
          }
          cVar1 = (**(code **)(**(int **)(param_1 + 0x3c) + 0x54))(&local_20,param_4,0,local_c);
          if (cVar1 != '\0') {
            (**(code **)(**(int **)(param_1 + 0x3c) + 0x58))(&local_20,param_4,0,local_c,1);
          }
          FUN_00486f2a();
          if (((*(int *)(*(int *)(param_1 + 0x3c) + 0x1ac) == 0) ||
              (*(short *)(*(int *)(param_1 + 0x3c) + 0x1b0) == 0)) &&
             (*(char *)(param_1 + 0x74) != '\0')) {
            if ((*(char *)(param_1 + 0xad) != '\0') && (iVar5 = FUN_00492b26(), 1 < iVar5)) {
              DAT_006e4a7c = 0x1f;
            }
            FUN_004864ed(DAT_006e4a7c,0xffffffff);
          }
          else {
            FUN_004d2900(0);
            DAT_006c5e40 = 0xffffffff;
          }
          goto LAB_00486092;
        }
        *(undefined4 *)(param_1 + 0x7c) = 0xffffffff;
        iVar5 = param_5;
      }
      sStack_e = (short)((uint)*(undefined4 *)(iVar5 + 0xc) >> 0x10);
      local_10 = (short)*(undefined4 *)(iVar5 + 0xc);
      _local_10 = CONCAT22(sStack_e - *(short *)(param_1 + 0x50),
                           local_10 - *(short *)(param_1 + 0x54));
      puVar6 = (undefined4 *)FUN_004a6a9d(local_18,&local_10,1);
      param_2 = *puVar6;
      param_3 = puVar6[1];
      FUN_0047bd91(&param_3,&param_2,-*(int *)(DAT_006e54d8 + 0x84) & 3,0x400);
      local_28 = param_2;
      local_24 = param_3;
      FUN_004860a0();
      *(undefined1 *)(param_1 + 0x95) = 0;
      if (*(int *)(param_1 + 0x3c) == 0) goto LAB_00486092;
      cVar1 = FUN_00432644();
      if (cVar1 != '\0') {
        (**(code **)(**(int **)(param_1 + 0x3c) + 0x50))(1);
      }
      iVar5 = *(int *)(*(int *)(param_1 + 0x3c) + 0x1ac);
      if (iVar5 != 0) {
        FUN_00486ec8(CONCAT22((short)((uint)iVar5 >> 0x10),*(undefined2 *)(iVar5 + 0xf0)),0);
      }
      cVar1 = FUN_00422665(&param_2);
      uVar4 = param_4;
      if (cVar1 != '\0') goto LAB_00486092;
      param_5 = 0;
      cVar1 = (**(code **)(**(int **)(param_1 + 0x3c) + 0x54))(&param_2,param_4,0,local_c);
      if (cVar1 == '\0') {
LAB_00486056:
        cVar1 = (**(code **)(**(int **)(param_1 + 0x3c) + 0x54))(&local_28,uVar4,0,0);
        if (cVar1 == '\0') {
          (**(code **)(**(int **)(param_1 + 0x3c) + 0x50))(1);
        }
        else {
          (**(code **)(**(int **)(param_1 + 0x3c) + 0x58))(&local_28,uVar4,0,0);
        }
        if (param_5 != 0) {
          DAT_006e4a7c = param_5;
        }
      }
      else {
        (**(code **)(**(int **)(param_1 + 0x3c) + 0x58))(&param_2,uVar4,0,local_c,1);
        if ((*(int *)(*(int *)(param_1 + 0x3c) + 0x1ac) == 0) ||
           (*(short *)(*(int *)(param_1 + 0x3c) + 0x1b0) == 0)) {
          if (*(int *)(param_1 + 0x34) == 5) {
            cVar1 = FUN_00487563();
            if (cVar1 != '\0') {
              (**(code **)(**(int **)(param_1 + 0x3c) + 0x58))(&param_2,uVar4,0,local_c,1);
              if ((*(int *)(*(int *)(param_1 + 0x3c) + 0x1ac) != 0) &&
                 (*(short *)(*(int *)(param_1 + 0x3c) + 0x1b0) != 0)) goto LAB_0048608b;
              param_5 = DAT_006e4a7c;
              if (*(int **)(param_1 + 0x30) != (int *)0x0) {
                (**(code **)(**(int **)(param_1 + 0x30) + 0xc))();
              }
            }
          }
          else {
            cVar1 = FUN_0048749e();
            if ((cVar1 != '\0') ||
               ((*(int *)(*(int *)(param_1 + 0x3c) + 0x1ac) != 0 &&
                (*(short *)(*(int *)(param_1 + 0x3c) + 0x1b0) != 0)))) goto LAB_0048608b;
          }
          goto LAB_00486056;
        }
      }
LAB_0048608b:
      FUN_00486f2a();
      goto LAB_00486092;
    }
    iVar5 = FUN_00492b10(param_4);
    uVar3 = 0;
    uVar4 = param_4;
    if (iVar5 == 0) {
      FUN_00486ec8(0,0);
      *(undefined1 *)(param_1 + 0x80) = 0;
      FUN_00486472();
      goto LAB_00486092;
    }
  }
  else {
    if ((*(int *)(param_1 + 0x3c) != 0) && (cVar1 = FUN_00432644(), cVar1 != '\0')) {
      (**(code **)(**(int **)(param_1 + 0x3c) + 0x50))(1);
    }
    param_4 = *(uint *)(param_5 + 0xc);
    FUN_004a6a9d(local_18,&param_4,0);
    uVar4 = FUN_004a6abd(&param_4,uVar3,(*(int *)(param_1 + 0x34) != 3) + '\x02');
    iVar5 = FUN_00492b10(uVar4);
    uVar3 = 1;
    uVar4 = -(uint)(iVar5 != 0) & uVar4;
  }
  FUN_00486ec8(uVar4,uVar3);
LAB_00486092:
  FUN_00486e21();
  return;
}

