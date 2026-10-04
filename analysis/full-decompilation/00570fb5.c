
int FUN_00570fb5(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_00407498(param_1);
  iVar2 = FUN_006359f2(iVar1,0,&cXObject::RTTI_Type_Descriptor,&cXPerson::RTTI_Type_Descriptor,0);
  switch(param_2) {
  case 0:
    if (iVar2 != 0) {
      if ((((uint)(int)*(short *)(iVar2 + 0x620) >> 2 & 1) == 0) &&
         (((uint)(int)*(short *)(iVar2 + 0x620) >> 3 & 1) == 0)) {
        if (*(short *)(iVar2 + 0x600) < 0xc) {
          return 2;
        }
        return (int)*(short *)(iVar2 + 0x60e);
      }
      return 1000;
    }
    break;
  case 1:
    if (iVar2 != 0) {
      return (int)*(short *)(iVar2 + 0x600);
    }
    break;
  case 2:
    if (iVar2 != 0) {
      iVar1 = (int)*(short *)(iVar2 + 0x5a0);
code_r0x00571061:
      return iVar1 / 10;
    }
    break;
  case 3:
    if (iVar2 != 0) {
      iVar1 = (int)*(short *)(iVar2 + 0x59e);
      goto code_r0x00571061;
    }
    break;
  case 4:
    return (int)*(short *)(*(int *)(DAT_006e486c + 0x1c) + 0x10);
  case 5:
    if (iVar2 != 0) {
      iVar1 = (int)*(short *)(iVar2 + 0x5aa);
      goto code_r0x00571061;
    }
    break;
  case 6:
    if (iVar2 != 0) {
      iVar1 = (int)*(short *)(iVar2 + 0x5a2);
      goto code_r0x00571061;
    }
    break;
  case 7:
    if (iVar2 != 0) {
      iVar1 = (int)*(short *)(iVar2 + 0x5a4);
      goto code_r0x00571061;
    }
    break;
  case 0xb:
    if (iVar2 != 0) {
      iVar1 = (int)*(short *)(iVar2 + 0x5ae);
      goto code_r0x00571061;
    }
    break;
  case 0xc:
    if (iVar2 != 0) {
      iVar1 = (int)*(short *)(iVar2 + 0x5b0);
      goto code_r0x00571061;
    }
    break;
  case 0xd:
    if ((iVar1 != 0) && (iVar1 = FUN_004670a4(*(undefined2 *)(iVar1 + 0x84)), iVar1 != 0)) {
      iVar1 = FUN_004681ec();
      return iVar1;
    }
    return 100;
  case 0xe:
    if (iVar2 != 0) {
      FUN_0045d283(3);
      iVar1 = __ftol();
      return iVar1;
    }
    break;
  case 0xf:
    if (iVar2 != 0) {
      iVar1 = (int)*(short *)(iVar2 + 0x590);
      goto code_r0x00571061;
    }
    break;
  case 0x10:
    if (iVar2 != 0) {
      iVar1 = (int)*(short *)(iVar2 + 0x592);
      goto code_r0x00571061;
    }
    break;
  case 0x11:
    if (iVar2 != 0) {
      iVar1 = (int)*(short *)(iVar2 + 0x594);
      goto code_r0x00571061;
    }
    break;
  case 0x12:
    if (iVar2 != 0) {
      iVar1 = (int)*(short *)(iVar2 + 0x596);
      goto code_r0x00571061;
    }
    break;
  case 0x13:
    if (iVar2 != 0) {
      iVar1 = (int)*(short *)(iVar2 + 0x598);
      goto code_r0x00571061;
    }
    break;
  case 0x14:
    if (iVar2 != 0) {
      iVar1 = (int)*(short *)(iVar2 + 0x59a);
      goto code_r0x00571061;
    }
  }
  return 0;
}

