//===-- RISCVMCAsmInfo.cpp - RISCV asm properties ---------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#include "RISCVMCAsmInfo.h"
#include "llvm/MC/MCContext.h"
#include "llvm/MC/MCSectionELF.h"

using namespace llvm;

RISCVMCAsmInfo::RISCVMCAsmInfo(const Target &T, StringRef TT) {
  PointerSize = 8;
  CalleeSaveStackSlotSize = 8;
  IsLittleEndian = false;

  CommentString = "#";
  PCSymbol = ".";
  GlobalPrefix = "";
  PrivateGlobalPrefix = ".L";
  WeakRefDirective = "\t.weak\t";
  ZeroDirective = "\t.space\t";
  Data64bitsDirective = "\t.quad\t";
  UsesELFSectionDirectiveForBSS = true;
  SupportsDebugInformation = true;
  HasLEB128 = true;
  ExceptionsType = ExceptionHandling::DwarfCFI;
}

const MCSection *
RISCVMCAsmInfo::getNonexecutableStackSection(MCContext &Ctx) const {
  return Ctx.getELFSection(".note.GNU-stack", ELF::SHT_PROGBITS,
                           0, SectionKind::getMetadata());
}
