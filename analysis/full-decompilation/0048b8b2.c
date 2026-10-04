
char __thiscall FUN_0048b8b2(int param_1,undefined1 *param_2)

{
  char cVar1;
  char cVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint local_10;
  uint local_c;
  char local_5;
  
  if (*(char *)(param_1 + 0x71) != '\0') {
    local_5 = '\x01';
    cVar1 = FUN_0048b9cf((undefined1 *)(param_1 + 0x33));
    if (cVar1 != '\0') {
      *(undefined1 *)(param_1 + 0x33) = *param_2;
      *(undefined1 *)(param_1 + 0x34) = param_2[1];
      *(undefined1 *)(param_1 + 0x35) = param_2[2];
      FUN_00434d3d(&local_10);
      uVar5 = local_10 & 0xfffffff1 | 1;
      uVar3 = local_c & 0xfffffff1 | 1;
      cVar1 = param_2[2];
      local_10 = uVar5;
      local_c = uVar3;
      FUN_0047bd91(&local_c,&local_10,-*(int *)(DAT_006e54d8 + 0x84) & 3,0x400);
      if ((*(int **)(param_1 + 0x2c) == (int *)0x0) ||
         (cVar2 = (**(code **)(**(int **)(param_1 + 0x2c) + 0x54))(&local_10,(int)cVar1,0,0),
         cVar2 == '\0')) {
        (**(code **)(**(int **)(param_1 + 0x2c) + 0x50))(1);
        local_5 = '\0';
      }
      else {
        (**(code **)(**(int **)(param_1 + 0x2c) + 0x58))(&local_10,(int)cVar1,0,0,1);
      }
      DAT_006e57d8 = uVar5;
      DAT_006e57dc = uVar3;
      if (((*(int *)(param_1 + 0x5c) != 0) && (*(char *)(*(int *)(param_1 + 0x5c) + 0xe024) != '\0')
          ) && (local_5 != '\0')) {
        uVar4 = FUN_00492b26();
        FUN_00540a5b(uVar4);
        FUN_00540eb1(uVar4);
      }
    }
    return local_5;
  }
  if (*(int **)(param_1 + 0x2c) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x2c) + 0x50))(1);
  }
  return '\0';
}

